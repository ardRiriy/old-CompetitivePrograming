// -*- coding:utf-8-unix -*-

use std::cmp::Reverse;
use std::collections::BinaryHeap;
use std::vec::Vec;
use proconio::input;


////////////////////////////

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

//////////////////////////

fn solve(){

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
