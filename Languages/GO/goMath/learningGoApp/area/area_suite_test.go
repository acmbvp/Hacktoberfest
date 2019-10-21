package area_test

import (
	"testing"

	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

func TestArea(t *testing.T) {
	RegisterFailHandler(Fail)
	RunSpecs(t, "Area Suite")
}
