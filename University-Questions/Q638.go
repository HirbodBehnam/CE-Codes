package main

import (
	"fmt"
	"math/big"
	"strconv"
)

// I used golang because of big.Int struct
func main() {
	triangleRow := make([]*big.Int, 100 + 1)
	sum := new(big.Int).SetInt64(1)
	triangleRow[0] = new(big.Int).SetInt64(1)
	triangleRow[1] = new(big.Int).SetInt64(1)
	var n int
	{
		var input string
		fmt.Scanln(&input)
		n, _ = strconv.Atoi(input)
	}
	if n == 0{
		fmt.Println("0")
		return
	}
	// use pascal's triangle to calculate the series
	for i := 2; i <= n; i++ {
		temp := new(big.Int).SetInt64(1)
		for  j := 1; j < i; j++{
			veryTemp := new(big.Int).SetBytes(triangleRow[j].Bytes()) // copy the big int
			triangleRow[j].Add(triangleRow[j], temp)
			temp = veryTemp
		}

		triangleRow[i] = new(big.Int).SetInt64(1)
		multiply := new(big.Int).SetInt64(1)
		// this could be optimized a bit by going halfway and multiplying raising the answer to power of 2. (and multiply the middle element if necessary)
		for j := 0; j <= i; j++ {
			multiply.Mul(multiply, triangleRow[j])
		}
		sum.Add(sum,multiply)
	}
	fmt.Println(sum.String())
}
