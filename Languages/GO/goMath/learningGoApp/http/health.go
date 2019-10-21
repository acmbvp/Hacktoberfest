package http

import (
	"net/http"

	"github.com/gorilla/mux"
)

func addHealthHandler(router *mux.Router) {

	// resp, err := http.Get("localhost:8080/health")
	// if err != nil {
	// 	log.Fatal(err)
	// }

	router.
		Methods("GET").
		Path("/health").
		HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
			w.Write([]byte{})
		})

}
