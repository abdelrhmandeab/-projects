const wrapper = document.querySelector('.wrapper');
const loginlink=document.querySelector('.log-link');
const registerlink=document.querySelector('.reg-link');

registerlink.addEventListener('click',()=>{
    wrapper.classList.add('active');
});
loginlink.addEventListener('click',()=>{
    wrapper.classList.remove('active');
});