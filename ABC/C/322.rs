// -*- coding:utf-8-unix -*-

use std::iter::Iterator;
use std::string::String;
use proconio::input;
use std::io::{self, Write};


fn solve(){
    input! {
        n: usize,
        m: usize,
        a: [usize;m],
    }
    
    for i in 0..n {
        let (Ok(idx) | Err(idx)) = a.binary_search(&(i+1));
        println!("{}", a[idx] - i - 1);
    }
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
