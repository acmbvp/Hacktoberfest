import { eliminarMensaje } from "./functions.js";
let comentar = document.getElementById("comentar");
let userInfo = JSON.parse(localStorage.getItem("token"));
const urlPost = "http://localhost:3000/publicaciones";
let idPublicacion;
let urlPublicaciones = "http://localhost:3000/publicaciones/";

const section = document.createElement("section");
section.style.display = "flex";
section.id = "mensajes";
section.className = "container";

const img = document.createElement("img");
img.className = "foto";
img.src = userInfo.foto;

const textarea = document.createElement("textarea");
textarea.id = "inputTexto";
textarea.placeholder = "Add a comment..";

const button = document.createElement("button");
button.id = "btnSend";
button.className = "btn-send";
button.type = "button";
button.textContent = "SEND";

section.appendChild(img);
section.appendChild(textarea);
section.appendChild(button);

comentar.appendChild(section);

document.addEventListener("DOMContentLoaded", (e) => {
  let comentar = document.getElementById("comentar"),
    alertLog = document.querySelector(".no-loged"),
    logReg = document.querySelector(".log-reg"),
    cerrar = document.getElementById("cerrar"),
    publicacionesContainer = document.getElementById("publicaciones");

  if (localStorage.getItem("token")) {
    cerrar.style.display = "flex";
    logReg.style.display = "none";
    alertLog.style.display = "none";
    comentar.style.display = "flex";
  }
  fetch(urlPost)
    .then((response) => {
      if (!response.ok) {
        throw new Error("Hubo un problema al realizar la solicitud.");
      }
      return response.json();
    })
    .then((data) => {
      data.forEach((info) => {
        const publicacionDiv = document.createElement("div");
        publicacionDiv.id = info.id;
        publicacionDiv.classList.add("info");

        const usuario = document.createElement("h4");
        usuario.textContent = info.usuario;

        const fotoPerfilImg = document.createElement("img");
        fotoPerfilImg.src = info.fotoPerfil;
        fotoPerfilImg.alt = `Foto de perfil de ${info.usuario}`;

        const mensaje = document.createElement("p");
        mensaje.textContent = info.mensaje;
        mensaje.classList.add("msg");

        const btnDelete = document.createElement("button");
        btnDelete.textContent = "Delete";
        btnDelete.classList.add("deleteBtn");
        btnDelete.onclick = eliminarMensaje;

        const btnEdit = document.createElement("button");
        btnEdit.textContent = "Edit";
        btnEdit.classList.add("editBtn");

        publicacionDiv.appendChild(usuario);
        publicacionDiv.appendChild(fotoPerfilImg);
        publicacionDiv.appendChild(mensaje);
        publicacionDiv.appendChild(btnDelete);
        publicacionDiv.appendChild(btnEdit);

        publicacionesContainer.appendChild(publicacionDiv);
      });
    })
    .catch((error) => {
      console.error("Error:", error);
    });
});

document.addEventListener("click", (e) => {
  e.preventDefault();
  if (e.target.textContent === "Cerrar sesion") {
    localStorage.removeItem("token");
    location.reload();
  }
});
btnSend.addEventListener("click", (e) => {
  e.preventDefault();
  if (btnSend.textContent === "Guardar") {
    let mensajeEditado = document.getElementById("inputTexto").value;
    let mensajeActualizado = {
      mensaje: mensajeEditado,
      usuario: userInfo.usuario,
      fotoPerfil: userInfo.foto,
    };

    let requestOptions = {
      method: "PUT",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(mensajeActualizado),
    };

    fetch(urlPublicaciones + idPublicacion, requestOptions)
      .then((response) => response.text())
      .catch((error) => console.log("error", error));
    btnSend.textContent = "SEND";
  } else {
    const timestamp = new Date().getTime();
    const mensajeValue = document.getElementById("inputTexto").value;
    const dataPost = {
      mensaje: mensajeValue,
      usuario: userInfo.usuario,
      fotoPerfil: userInfo.foto,
      fecha: timestamp,
    };

    fetch(urlPost, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(dataPost),
    });
  }
});
document.addEventListener("click", (e) => {
  if (e.target.textContent === "Edit") {
    let publicacion = e.target.closest(".info");
    idPublicacion = publicacion.getAttribute("id");
    let mensajeActual = publicacion.querySelector("p").textContent;
    let inputEditar = document.getElementById("inputTexto");
    btnSend.textContent = "Guardar";
    inputEditar.textContent = mensajeActual;
  }
});
