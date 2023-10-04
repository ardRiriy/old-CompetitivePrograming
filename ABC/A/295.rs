// -*- coding:utf-8-unix -*-

use std::iter::Iterator;
use std::string::String;
use proconio::input;
use std::io::{self, Write};


fn solve(){
    input! {
        n: usize,
        w: [String; n],
    }

    for s in w {
        let S: &str = &s;
        match S {
            "and" => {
                println!("Yes");
                return;
            },
            "not" => {
                println!("Yes");
                return;
            },
            "that" => {
                println!("Yes");
                return;
            },
            "the" => {
                println!("Yes");
                return;
            },
            "you" => {
                println!("Yes");
                return;
            },
            _ => {
                
            }
        }
    }
    println!("No");
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
