document.addEventListener('DOMContentLoaded', function() {

    let input = document.querySelector('input');  // selecting from the document the on and only input tag

    input.addEventListener('keyup', function(event) { // whenever the user releases a key the event takes place and the function isb carried out
        let name = document.querySelector('p');// the variable name is assign to the tag p
        if (input.value) { // means if the input has some value
            name.innerHTML = `hello, ${input.value}`; //her euse ` instead of ' in java script when you are about to show that on the screen
        }
        else {
            name.innerHTML = 'hello, whoever you are';
        }
    });
});