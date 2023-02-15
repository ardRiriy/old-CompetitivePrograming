// なぜか通らない　なんでなん？
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	n := bufio.NewScanner(os.Stdin)
	n.Scan()
	var num int
	num, _ = strconv.Atoi(n.Text())

	s := bufio.NewScanner(os.Stdin)
	s.Scan()

	//空白区切りで配列に格納
	card := strings.Split(s.Text(), " ")

	exp := adder(num)
	var actual int
	actual = 0

	for _, x := range card {
		var i int
		i, _ = strconv.Atoi(x)
		actual += i
	}
	fmt.Println(strconv.Itoa(exp - actual))
}

func adder(a int) int {
	if a == 0 {
		return 0
	}
	return 4*a + adder(a-1)
}
