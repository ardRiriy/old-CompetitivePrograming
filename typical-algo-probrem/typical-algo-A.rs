// -*- coding:utf-8-unix -*-

use std::iter::Iterator;
use std::string::String;
use proconio::input;
use std::io::{self, Write};


fn solve(){
    input! {
        n: usize,
        k: usize,
        a: [usize;n],
    }

    match a.binary_search(&k) {
        Ok(idx) => {
            println!("{}", idx);
        },
        Err(idx) => {
            if idx == n {
                println!("-1");
            }else{
                println!("{}", idx);
            }
        }
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
