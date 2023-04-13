
//Window.onload = loadPage();

var output = 'hehe';

window.addEventListener('load', () => {
    
    const newForm = document.querySelector('#new-form');
    alert('hello');
    //main();
    newForm.addEventListener('submit', e => {
        e.preventDefault();
        main();
    });

})

function main()
{
   // category.innerHTML =  `<h3 type="text" size="30" value="hello: " readonly>`;
    alert('in main');
    const output = document.createElement('div');
    document.write('<input type="text" size="30" value="${output}: " readonly>');
    document.createElement `<input type="text" size="30" value="${output}: " readonly>`;
    output.innerHTML = `<input type="text" size="30" value="${output}: " readonly>`;
    //app.appendChild(output);
}

