// -*- coding:utf-8-unix -*-

use std::cmp::Reverse;
use std::collections::BinaryHeap;
use std::vec::Vec;
use proconio::input;

fn solve(){
    input! {
        n: usize,
        mut a: [usize; n],
    }

    a.sort_by(|a, b| b.cmp(a));

    let mut ans = 0;
    let mut i = 0;
    while i < n - 1 {
        if a[i] == a[i + 1] {
            if ans == 0 {
                ans = a[i];
                i += 1;
            } else {
                ans *= a[i];
                break;
            }
        }
        i += 1;
    }
    println!("{}", ans);
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
