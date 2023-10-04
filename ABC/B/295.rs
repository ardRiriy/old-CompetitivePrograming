// -*- coding:utf-8-unix -*-

use std::iter::Iterator;
use std::string::String;
use proconio::input;
use std::io::{self, Write};


fn solve(){
    input! {
        r: usize,
        c: usize,
        mut b_string: [String; r],
    }

    let mut b: Vec<Vec<char>> = Vec::new();
    for s in b_string.iter() {
        let chars: Vec<char> = s.chars().collect();
        b.push(chars);
    }
    
    for i in 0..r {
        for j in 0..c {
            if b[i][j] != '.' && b[i][j] != '#' {
                let num :usize = b[i][j] as usize - 48;
                for ii in 0..r {
                    for jj in 0..c {
                        if b[ii][jj] != '#' {
                            continue;
                        }
                        let a = {
                            if i >= ii {
                                i - ii 
                            }else{
                                ii - i
                            }
                        };
                        let bb = {
                            if j >= jj {
                                j - jj
                            }else {
                                jj - j
                            }
                        };

                        if num >= a + bb {
                            b[ii][jj] = '.';
                        }
                    }
                }
                b[i][j] = '.';
            }
        }
    }

    for i in 0..r {
        for j in 0..c {
            print!("{}", b[i][j]);
        }
        println!("");
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
