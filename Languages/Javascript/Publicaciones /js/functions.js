export function eliminarMensaje(e) {
  let publicacion = e.target.closest(".info");
  let idPublicacion = publicacion.getAttribute("id");

  fetch("http://localhost:3000/publicaciones/" + idPublicacion, {
    method: "DELETE",
    headers: {
      "Content-Type": "application/json",
    },
  });
}
