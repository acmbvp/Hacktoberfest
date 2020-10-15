import React, { useContext } from "react";
import { v4 } from "uuid";
import Loader from "react-spinners/PacmanLoader";
import MovieCard from "./MovieCard";
import { Context } from "../Context/Context";

export default function Movies() {
	const { searchResults, isLoading } = useContext(Context);

	if (!isLoading && searchResults instanceof Array) {
		return (
			<div className="movies__result">
				{searchResults.map((movie) => (
					<MovieCard key={v4()} movie={movie} />
				))}
			</div>
		);
	} else {
		return (
			<div className="loader__container">
				<Loader color="#f85210" />
				<h3>Fetching Resources....</h3>
			</div>
		);
	}
}
