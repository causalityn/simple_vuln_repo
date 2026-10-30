package main

import (
	"net/http"
	"os"
)

func main() {
	http.HandleFunc("/read", func(w http.ResponseWriter, r *http.Request) {
		data, _ := os.ReadFile(r.URL.Query().Get("file")) // path traversal
		w.Write(data)
	})
	http.ListenAndServe(":8080", nil)
}
