let body = document.querySelector('body');
document.querySelector('#red').addEventListener('click', function() {
    body.style.backgroundColor = 'red';
});
document.querySelector('#green').addEventListener('click', function() {
    body.style.backgroundColor = 'green'; // accessing body then its style then into backgroundColor and setting it to green
});
document.querySelector('#blue').addEventListener('click', function() {
    body.style.backgroundColor = 'blue';
});
