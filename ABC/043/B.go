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
	input := s.Text()
	for i := 0; i < len(input); i++ {
		input = strings.Replace(input, "0B", "", 1)
		input = strings.Replace(input, "1B", "", 1)
	}
	input = strings.Replace(input, "B", "", -1)
	fmt.Println(input)
}
