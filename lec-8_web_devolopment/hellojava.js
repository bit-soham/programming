document.addEventListener('DOMContentLoaded', function() {
    // it selcts its query from form which is not yet read therefore we must first read everything then excecute this

    document.querySelector('form').addEventListner('submit', function(event){ // it listen when the event or action of submit takes place the function is executed

        let name = document.querySelector('#name').value; // the function is explained dynamicly

        alert('hello, '+ name);

        event.preventDefault(); // it does what return="false would do in an html file"

        //it just does the function of not doing the thing it was suppoesed to do submit the form after the event was excecuted
    });
});