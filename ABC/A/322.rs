// -*- coding:utf-8-unix -*-

use std::iter::Iterator;
use std::process::exit;
use std::string::String;
use proconio::input;

fn main() {
    input! {
        n: usize,
        s: String,
    }

    let v: Vec<char> = s.chars().collect();

    for i in 0..n-2 {
        if v[i] == 'A' && v[i+1] == 'B' && v[i+2] == 'C' {
            println!("{}", i+1);
            exit(0);
        }
    }
    println!("{}", -1);
}
