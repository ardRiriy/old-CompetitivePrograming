package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Scan()

	//空白区切りで配列に格納
	inputs := strings.Split(s.Text(), " ")

	fmt.Println(inputs[0])
}
