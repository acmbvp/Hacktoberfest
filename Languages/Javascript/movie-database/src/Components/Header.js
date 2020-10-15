import React, { useContext, useState } from "react";
import { Context } from "../Context/Context";
import Logo from "react-ionicons/lib/MdVideocam";

export default function Header() {
	const [error, setError] = useState("");
	const [movieName, setMovieName] = useState("");
	const { setIsLoading, setSearchResults } = useContext(Context);

	console.log(process.env.REACT_APP_KEY);

	const fetchMovie = async (e) => {
		e.preventDefault();

		// if movie name is set
		if (movieName) {
			// clear the error message
			setError("");

			// set isLoading to true in the context
			setIsLoading(true);

			try {
				const data = await fetch(
					`http://www.omdbapi.com/?s=${encodeURI(movieName)}&apikey=${
						process.env.REACT_APP_KEY
					}`
				);
				const json = await data.json();

				setSearchResults(json.Search);

				// set is loading to false in the context
				setIsLoading(false);
			} catch (err) {
				console.log(err);
			}
		} else {
			setError("Movie Name cannot be empty!!");
		}
	};

	return (
		<header>
			<h1>
				<Logo color="#f85210" fontSize="30px" /> Movie Database
			</h1>
			<form action="">
				<input
					type="text"
					placeholder="Movie name"
					onChange={(e) => setMovieName(e.target.value)}
				/>
				<button onClick={(e) => fetchMovie(e)}>Search</button>
			</form>
			{error.length !== 0 && <small class="error">{error}</small>}
		</header>
	);
}
