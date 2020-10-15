import React from "react";
import Home from "./Components/Home";
import Movie from "./Components/Movie";
import { Route } from "react-router-dom";

// importing CSS
import "./assets/css/styles.css";

export default function App() {
	return (
		<>
			<Route path="/" component={Home} exact />
			<Route path="/movie/:id" component={Movie} />
		</>
	);
}
