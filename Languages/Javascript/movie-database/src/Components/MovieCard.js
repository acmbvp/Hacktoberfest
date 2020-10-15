import React from "react";
import { Link } from "react-router-dom";

export default function MovieCard({ movie }) {
	console.log(movie);

	return (
		<Link to={`/movie/${movie.imdbID}`}>
			<div className="movie__card">
				<img src={movie.Poster} alt="" />
				<h4>{movie.Title}</h4>
			</div>
		</Link>
	);
}
