const btnEnviar = document.getElementById("btn-enviar");
const url = "http://127.0.0.1:3000/users/";
btnEnviar.addEventListener("click", (e) => {
  const correo = document.getElementById("correo").value,
    nombre = document.getElementById("nombre").value,
    foto = document.getElementById("foto").value,
    password = document.getElementById("password").value;

  e.preventDefault();

  let usuario = {
    usuario: nombre,
    foto: foto,
    correo: correo,
    password: password,
    active: false,
  };
  console.log(usuario);
  fetch(url, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(usuario),
  });
  window.location.href = "./index.html";
});
