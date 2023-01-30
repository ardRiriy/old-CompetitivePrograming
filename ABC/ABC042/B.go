// あきらめている(深夜テンション～カタンを添えて～)
package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Scan()

	//空白区切りで配列に格納
	nl := strings.Split(s.Text(), " ")
	var n, l int

	n, _ = strconv.Atoi(nl[0])
	l, _ = strconv.Atoi(nl[1])
	for i := 0; i < n; i++ {

	}
}
