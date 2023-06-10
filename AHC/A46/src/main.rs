use core::time;
use proconio::input;
use rand::Rng;
use std::{ptr::swap, u64::MAX};

#[derive(Debug, Clone)]
struct TimeKeeper {
    start_time: std::time::Instant,
    time_threshold: f64,
}

impl TimeKeeper {
    fn new(time_threshold: f64) -> Self {
        TimeKeeper {
            start_time: std::time::Instant::now(),
            time_threshold,
        }
    }
    #[inline]
    fn isTimeOver(&self) -> bool {
        let elapsed_time = self.start_time.elapsed().as_nanos() as f64 * 1e-9;
        #[cfg(feature = "local")]
        {
            elapsed_time * 0.85 >= self.time_threshold
        }
        #[cfg(not(feature = "local"))]
        {
            elapsed_time >= self.time_threshold
        }
    }
}

fn main() {
    let time_keeper = TimeKeeper::new(0.985);
    input! {
        N: u64,
        P: [[u64; 2]; N],
    }

    let mut ans = Vec::new();
    let mut ck: [bool; 150] = [false; 150];
    ck[0] = true;

    let mut now = 0;
    ans.push(0);
    let mut next = 0;
    // 初期解
    loop {
        let mut min = MAX;
        for i in 0..N {
            if i == now || ck[i as usize] {
                continue;
            }
            let d = distance(
                P[i as usize][0],
                P[i as usize][1],
                P[now as usize][0],
                P[now as usize][1],
            );
            if min > d {
                min = d;
                next = i;
            }
        }
        ck[next as usize] = true;
        ans.push(next);
        now = next;

        if ans.len() == N as usize {
            break;
        }
    }

    ans.push(0);

    let mut rang = rand::thread_rng();
    while !time_keeper.isTimeOver() {
        let mut i: usize;
        loop {
            i = rang.gen_range(1..N) as usize;
            if i + 1 != N as usize {
                break;
            }
        }
        let mut k: usize;
        loop {
            k = rang.gen_range(1..N) as usize;
            if i != k {
                break;
            }
        }
        if i > k {
            unsafe { swap(&mut i, &mut k) };
        }
        let pre_score = distance(
            P[ans[i] as usize][0],
            P[ans[i] as usize][1],
            P[ans[(i + 1) as usize] as usize][0],
            P[ans[(i + 1) as usize] as usize][1],
        ) + distance(
            P[ans[k] as usize][0],
            P[ans[k] as usize][1],
            P[ans[(k + 1) as usize] as usize][0],
            P[ans[(k + 1) as usize] as usize][1],
        );
        let new_score = distance(
            P[ans[i] as usize][0],
            P[ans[i] as usize][1],
            P[ans[k] as usize][0],
            P[ans[k] as usize][1],
        ) + distance(
            P[ans[(i + 1) as usize] as usize][0],
            P[ans[(i + 1) as usize] as usize][1],
            P[ans[(k + 1) as usize] as usize][0],
            P[ans[(k + 1) as usize] as usize][1],
        );

        if pre_score > new_score {
            ans[i + 1..=k].reverse();
        } else if new_score - pre_score > 3 && rang.gen_range(1..(new_score - pre_score)) == 1 {
            ans[i + 1..=k].reverse();
        }
    }

    for i in ans {
        println!("{}", i + 1);
    }
}

fn distance(x_1: u64, y_1: u64, x_2: u64, y_2: u64) -> u64 {
    let x = if x_1 > x_2 { x_1 - x_2 } else { x_2 - x_1 };
    let y = if y_1 > y_2 { y_1 - y_2 } else { y_2 - y_1 };
    x.pow(2) + y.pow(2)
}
