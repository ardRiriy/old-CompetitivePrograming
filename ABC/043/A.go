package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	fmt.Println(ans(n))
}

func ans(n int) int {
	if n == 1 {
		return 1
	}
	return n + ans(n-1)
}
