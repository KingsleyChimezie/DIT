
// Script to open and close sidebar
function openSide() {
    document.getElementById("sidebar").style.display = "block";
    document.getElementById("sidebarOverlay").style.display = "block";
}

function closeSide() {
    document.getElementById("sidebar").style.display = "none";
    document.getElementById("sidebarOverlay").style.display = "none";
}

function openLink(evt, animName) {
    closeSide();
    let i;
    let x;
    let tablinks;
    x = document.getElementsByClassName("resource");
    for (i = 0; i < x.length; i++) {
        x[i].style.display = "none";
    }
    tablinks = document.getElementsByClassName("tablink");
    for (i = 0; i < x.length; i++) {
        tablinks[i].className = tablinks[i].className.replace(" w3-white", "");
    }
    document.getElementById(animName).style.display = "block";
    evt.currentTarget.className += " w3-white";
}

function search() {
    var input, filter, table, tr, td, i;
    input = document.getElementById("searchInput");
    filter = input.value.toUpperCase();
    table = document.getElementById("searchTable");
    tr = table.getElementsByTagName("tr");
    for (i = 0; i < tr.length; i++) {
        td = tr[i].getElementsByTagName("td")[0];
        if (td) {
            if (td.innerHTML.toUpperCase().indexOf(filter) > -1) {
                tr[i].style.display = "";
            } else {
                tr[i].style.display = "none";
            }
        }
    }
}