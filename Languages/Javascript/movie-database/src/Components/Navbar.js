import React, { useState } from "react";
import { Link } from "react-router-dom";

export default function Navbar() {
	const [isOpen, setIsOpen] = useState(false);

	return (
		<>
			<a
				onClick={() => setIsOpen((isOpen) => !isOpen)}
				href="#!"
				className={`navbar__toggler ${isOpen ? "nav__toggler_active" : ""} `}
			>
				<span></span>
			</a>
			<nav className={`navbar__bg ${isOpen ? "navbar__bg_active" : ""}`}>
				<ul>
					<Link to="/">
						<li>Home</li>
					</Link>
					<a
						href="http://www.omdbapi.com/"
						target="_blank"
						rel="noopener noreferer"
					>
						<li>API</li>
					</a>
					<a
						href="https://github.com/codeshaan"
						target="_blank"
						rel="noopener noreferer"
					>
						<li>My Github</li>
					</a>
				</ul>
			</nav>
		</>
	);
}
