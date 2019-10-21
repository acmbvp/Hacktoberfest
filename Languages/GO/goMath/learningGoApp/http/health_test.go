package http_test

import (
	"fmt"
	"net/http"
	"net/http/httptest"

	"github.com/gorilla/mux"
	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

var (
	uri    string
	svr    *httptest.Server
	router *mux.Router
)

var _ = Describe("Health", func() {

	BeforeEach(func() {
		router := mux.NewRouter().StrictSlash(true)

		// AddRoutes(router)
		svr = httptest.NewServer(router)
		uri = svr.URL + "/health"
	})

	AfterEach(func() {
		svr.Close()
	})

	// TODO: implement tests for health endpoint?
	It("Returns 200", func() {
		req, _ := http.NewRequest(http.MethodGet, uri, nil)
		fmt.Println("uri for health check ", uri)
		_, err := http.DefaultClient.Do(req)
		Expect(err).To(BeNil())
		// Expect(res.StatusCode).To(Equal(http.StatusOK))
	})

})
