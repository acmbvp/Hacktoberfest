let btnLogin = document.getElementById("btn-login");
btnLogin.addEventListener("click", async (e) => {
  e.preventDefault();

  const email = document.getElementById("email").value,
    password = document.getElementById("password").value,
    urlUsuarios = "http://127.0.0.1:3000/users/";

  fetch(urlUsuarios, {
    method: "GET",
  })
    .then((response) => {
      if (!response.ok) {
        throw new Error(`HTTP error! Status: ${response.status}`);
      }
      return response.json();
    })
    .then((users) => {
      users.forEach((user) => {
        if (user.correo === email && user.password === password) {
          console.log(user);
          let dataUser = {
            usuario: user.usuario,
            foto: user.foto,
            correo: user.correo,
          };
          let usuarioJSON = JSON.stringify(dataUser);
          console.log(usuarioJSON);
          localStorage.setItem("token", usuarioJSON);
          window.location.href = "./index.html";
        }
      });
    });
});
