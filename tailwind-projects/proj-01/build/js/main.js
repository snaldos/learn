const initApp = () => {
  const hamburgerBtn = document.getElementById("hamburguer-button");
  const mobileMenu = document.getElementById("mobile-menu");
  const title = document.getElementById("title");
  const body = document.body;

  const toggleMenu = () => {
    mobileMenu.classList.toggle("hidden");
    mobileMenu.classList.toggle("flex");
    hamburgerBtn.classList.toggle("toggle-btn");
    body.classList.toggle("stop-scrolling");
  };

  hamburgerBtn.addEventListener("click", toggleMenu);
  mobileMenu.addEventListener("click", toggleMenu);

  title.addEventListener("click", () => {
    mobileMenu.classList.add("hidden");
    hamburgerBtn.classList.remove("toggle-btn");
  });

};

document.addEventListener("DOMContentLoaded", initApp);
