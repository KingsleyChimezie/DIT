let result = 0;
let operation = '';
let displayRefresh = false;

const calcResult = () => {
  const num = parseFloat(document.getElementsByTagName('input')[0].value);
  if (operation === '+') {
    result += num;
  } else if (operation === '-') {
    result -= num;
  } else if (operation === 'x' || operation === '*') {
    result *= num;
  } else if (operation === '÷' || operation === '/') {
    result /= num;
  } else {
    result = num;
  }
  document.getElementsByTagName('input')[0].value = result;
};

const processKey = key => {
  if (/\d/.test(key) || key === '.') {
    if (displayRefresh) {
      document.getElementsByTagName('input')[0].value = key;
      displayRefresh = false;
    } else {
      document.getElementsByTagName('input')[0].value += key;
    }
  } else if (key === 'C' || key === 'c') {
    result = 0;
    operation = '';
    document.getElementsByTagName('input')[0].value = '0';
  } else {
    calcResult();
    operation = key;
    displayRefresh = true;
  }
};

const btns = document.getElementsByClassName("flex-item");
[].forEach.call(btns, btn => {
  btn.onclick = () => {
    processKey(btn.textContent);
  };

});

document.getElementsByTagName('body')[0].addEventListener("keypress", event => {
  processKey(event.key);
});