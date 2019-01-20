package main

import (
	"fmt"

	"github.com/yourbasic/graph"
)

func main() {
	g := graph.New(30)
	g.Add(1, 2)
	g.Add(1, 3)
	g.Add(2, 4)
	g.Add(3, 4)
	g.Add(4, 6)
	path, _ := graph.ShortestPath(g, 1, 6)
	fmt.Print(g)
	fmt.Println("\npath:", path)

	g.Delete(1, 2)
	fmt.Print("\n", g)
}
