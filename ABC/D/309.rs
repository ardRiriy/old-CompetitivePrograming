// -*- coding:utf-8-unix -*-

use std::cmp::Reverse;
use std::collections::BinaryHeap;
use std::vec::Vec;
use proconio::input;

static INF: usize = 9223372036854775807;
#[derive(Clone)]
struct Edge {
    to: usize,
    cost: usize,
}

fn dijkstra (graph: &Vec<Vec<Edge>>, dist: &mut Vec<usize>, start: usize) {
    let mut heap = BinaryHeap::new();
    heap.push(Reverse((0usize, start)));

    while let Some(Reverse((cost, node))) = heap.pop() {
        if dist[node] != INF {
            continue;
        }
        dist[node] = cost;
        for edge in &graph[node] {
            if dist[edge.to] == INF {
                heap.push(Reverse((cost + edge.cost, edge.to)));
            }
        }
    }
}

fn solve(){
    input! {
        n1: usize,
        n2: usize,
        m: usize,
    }

    let mut g: Vec<Vec<Edge>> = vec![Vec::new(); n1 + n2];

    for _ in 0..m {
        input! {
            mut a: usize,
            mut b: usize,
        }
        a -= 1;
        b -= 1;
        g[a].push(Edge{to : b, cost : 1});
        g[b].push(Edge{to : a, cost : 1});
    }

    let mut d1 = vec![INF; n1 + n2];
    let mut d2 = vec![INF; n1 + n2];

    dijkstra(&g, &mut d1, 0);
    dijkstra(&g, &mut d2, n1 + n2 - 1);

    let mut mx1 = -1;
    let mut mx2 = -1;
    for i in 0..n1+n2 {
        if d1[i] != INF {
            mx1 = mx1.max(d1[i] as i64);
        }
        if d2[i] != INF {
            mx2 = mx2.max(d2[i] as i64);
        }
    }
    println!("{}", mx1 + mx2 + 1);
}


fn main() {
    let mut i: usize = 1;

    /*    /* 複数テストケースならコメントアウトを外す */
        let mut input = String::new();
        io::stdout().flush().unwrap();
        io::stdin().read_line(&mut input).unwrap();
        i = input.trim().parse().unwrap();*/

    while i != 0 {
        solve();
        i -= 1;
    }
}
