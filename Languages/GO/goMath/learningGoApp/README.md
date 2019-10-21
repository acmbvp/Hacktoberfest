To run the application, run:

go run main.go

The structure of the application is as follows:

├── calc
│   └── calc.go
└── main.go
The calc package contains the logic for the addition, multiplication, subtraction and division; each of them being a separate method of the package. For I/O, the application uses the fmt package.

TODO: finish
- add getting area of square, circle, rectangle, and triangle
- gets tests set up for each
- get a server connected (probably mux)
- create lightweight db to store all calculations that have been ran