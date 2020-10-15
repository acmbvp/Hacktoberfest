import React from "react";
import Movies from "./Movies";
import Header from "./Header";
import Navbar from "./Navbar";

export default function Home() {
	return (
		<>
			<Navbar />
			<div className="container">
				<Header />
				<Movies />
			</div>
		</>
	);
}
