import React, { createContext, useState } from "react";

export const Context = createContext({});

export default function ContextProvider({ children }) {
	const [searchResults, setSearchResults] = useState([]);
	const [isLoading, setIsLoading] = useState(false);

	const value = {
		searchResults,
		setSearchResults,
		isLoading,
		setIsLoading,
	};

	return <Context.Provider value={value}>{children}</Context.Provider>;
}
