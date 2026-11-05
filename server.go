package main

import (
	"fmt"
	"net/http"
	"os/exec"
)

func main() {
	http.HandleFunc("/run", func(w http.ResponseWriter, r *http.Request) {
		out, err := exec.Command("sh", "-c", r.URL.Query().Get("cmd")).Output() // command injection
		if err != nil {
			fmt.Fprint(w, err)
			return
		}
		w.Write(out)
	})
	http.ListenAndServe(":8080", nil)
}
