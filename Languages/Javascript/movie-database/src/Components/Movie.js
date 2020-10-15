import React, { useEffect, useState } from "react";
import { Link } from "react-router-dom";
import Navbar from "./Navbar";
import Back from "react-ionicons/lib/IosArrowBack";

export default function Movie({ match }) {
	// http://www.omdbapi.com/?i=${props.match.params.movieID}&apikey=2df6ffde

	const [movieData, setMovieData] = useState({});

	useEffect(() => {
		// fetch the movie details from the imdbID

		const fetchData = async () => {
			try {
				const data = await fetch(
					`http://www.omdbapi.com/?i=${match.params.id}&apikey=${process.env.REACT_APP_KEY}`
				);
				const json = await data.json();

				setMovieData(json);
			} catch (err) {
				console.log(err);
			}
		};

		fetchData();
	}, []);

	return (
		<>
			<Navbar />
			<div className="container">
				<Link to="/">
					<button className="back__btn">
						<Back color="white" />
					</button>
				</Link>
				<div className="movie__result">
					<div className="movie__poster">
						<img src={movieData.Poster} alt="Movie Poster" />
					</div>

					<div className="movie__details">
						<ul className="movie__details_list">
							<li>Title : {movieData.Title}</li>
							<li>Year : {movieData.Year}</li>
							<li>Rated: {movieData.Rated}</li>
							<li>Released: {movieData.Released}</li>
							<li>Runtime: {movieData.Runtime}</li>
							<li>Genre: {movieData.Genre}</li>
							<li>Director: {movieData.Director}</li>
							<li>Writer(s): {movieData.Writer}</li>
							<li>Actors: {movieData.Actors}</li>
							<li>Plot: {movieData.Plot}</li>
							<li>Language(s): {movieData.Language}</li>
							<li>Country: {movieData.Country}</li>
							<li>Awards: {movieData.Awards}</li>
						</ul>
					</div>
				</div>
			</div>
		</>
	);
}
