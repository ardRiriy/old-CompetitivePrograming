package main

import "fmt"

func main() {
	var n [3]int
	fmt.Scan(&n[0], &n[1], &n[2])
	if (n[0] == 5 && n[1] == 5 && n[2] == 7) || (n[0] == 5 && n[1] == 7 && n[2] == 5) || (n[0] == 7 && n[1] == 5 && n[2] == 5) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
