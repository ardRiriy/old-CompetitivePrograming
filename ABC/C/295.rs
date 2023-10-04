// -*- coding:utf-8-unix -*-

use std::iter::Iterator;
use std::collections::HashMap;
use proconio::input;


fn solve(){
    input! {
        n: usize,
        a: [usize; n],
    }
    let mut soc = HashMap::<usize, usize>::new();
    for i in a {
        *soc.entry(i).or_insert(0) += 1;
    }
    let mut ans = 0;
    
    for (_, s) in soc {
        ans += s/2;
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
