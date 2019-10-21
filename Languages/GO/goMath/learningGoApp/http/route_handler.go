package http

import (
	"github.com/gorilla/mux"
)

func AddRoutes(router *mux.Router) {
	addHealthHandler(router)
}
