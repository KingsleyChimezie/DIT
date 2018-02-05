import React, { Component } from 'react';
import './App.css';
import './Functions.js';
import axios from 'axios';
import 'w3-css/w3.css';

class App extends Component {
  
  constructor(props) {
    super(props);

    this.state = {
        inputsearch: '',
        routes: ["https://swapi.co/api/films/?search=", "https://swapi.co/api/people/?search=", "https://swapi.co/api/planet/?search=", "https://swapi.co/api/species/?search=", "https://swapi.co/api/starships/?search=", "https://swapi.co/api/vehicles/?search="],
        searchResults: []
    }
}

handleSearchChange(e) {
    this.setState({inputsearch: e.target.value});
}

componentWillMount() {
    let _this = this;

    this.getDataRequest = axios.get("https://swapi.co/api/films/?search=return&format=json")
        .then(function (response) {
            _this.setState({
                searchResults: JSON.parse(response['data']['results'])
            });
        })
        .catch(function (error) {
        });
}

componentWillUnmount() {
    this.getDataRequest.abort();
}
filmSearchHandler(e) {
    console.log("search was clicked" + this.state.inputsearch);
    fetch("https://swapi.co/api/films/?search="+this.state.inputsearch)
        .then(
            res => res.json())
        .then( res => {
            this.setState({searchResults: res});
        })

}
peopleSearchHandler(e) {
    console.log("search was clicked" + this.state.inputsearch);
    fetch("https://swapi.co/api/people/?search="+this.state.inputsearch)
        .then(
            res => res.json())
        .then( res => {
            this.setState({searchResults: res});
        })



}
starshipSearchHandler(e) {
    console.log("search was clicked" + this.state.inputsearch);
    fetch("https://swapi.co/api/starships/?search="+this.state.inputsearch)
        .then(
            res => res.json())
        .then( res => {
            this.setState({searchResults: res});
        })

}
vehicleSearchHandler(e) {
    console.log("search was clicked" + this.state.inputsearch);
    fetch("https://swapi.co/api/vehicles/?search="+this.state.inputsearch)
        .then(
            res => res.json())
        .then( res => {
            this.setState({searchResults: res});
        })

}
speciesSearchHandler(e) {
    console.log("search was clicked" + this.state.inputsearch);
    fetch("https://swapi.co/api/species/?search="+this.state.inputsearch)
        .then(
            res => res.json())
        .then( res => {
            this.setState({searchResults: res});
        })

}
planetsSearchHandler(e) {
    console.log("search was clicked" + this.state.inputsearch);
    fetch("https://swapi.co/api/planet/?search="+this.state.inputsearch)
        .then(
            res => res.json())
        .then( res => {
            this.setState({searchResults: res});
        })

}
  
  

  render() {
    return (
      
      <div className="App">
        <div>
          {/* !MENU! */}
          {/* Sidebar/menu */}
          <nav className="w3-sidebar w3-red w3-collapse w3-top w3-large w3-padding" style={{zIndex: 3, width: 300, fontWeight: 'bold'}} id="sidebar">
            <h3><b><img src="https://goo.gl/a335tc" alt="Stormtrooper face" height={64} width={64} /> Star Wars API</b></h3>
            <div className="w3-bar-block">
              <a href="#people" onclick="openLink(event, 'people')" className="tablink w3-bar-item w3-button w3-white w3-hover-red">People</a>
              <a href="#films" onclick="openLink(event, 'films')" className="tablink w3-bar-item w3-button w3-hover-red">Films</a>
              <a href="#starships" onclick="openLink(event, 'starships')" className="tablink w3-bar-item w3-button w3-hover-red">Starships</a>
              <a href="#vehicles" onclick="openLink(event, 'vehicles')" className="tablink w3-bar-item w3-button w3-hover-red">Vehicles</a>
              <a href="#species" onclick="openLink(event, 'species')" className="tablink w3-bar-item w3-button w3-hover-red">Species</a>
              <a href="#planets" onclick="openLink(event, 'planets')" className="tablink w3-bar-item w3-button w3-hover-red">Planets</a>
            </div>
          </nav>
          {/* Top menu on small screens */}
          <header className="w3-container w3-top w3-hide-large w3-red w3-xlarge w3-padding">
            <button className="w3-button w3-red w3-margin-right w3-hover-white" onclick="openSide()">☰</button>
            <span><img src="https://goo.gl/a335tc" alt="Stormtrooper face" height={32} width={32} /> Star Wars API</span>
          </header>
          {/* Overlay effect when opening sidebar on small screens */}
          <div className="w3-overlay w3-hide-large" onclick="closeSide()" style={{cursor: 'pointer'}} title="close side menu" id="sidebarOverlay" />
          {/* !PAGE CONTENT! */}
          <div className="w3-main" style={{marginLeft: 340, marginRight: 40}}>
            <div id="searchArea" className="w3-container w3-animate-right">
              {/* <input type="text" id="searchInput" onKeyUp={search()} placeholder="Search..." /> */}
            </div>
            {/* People */}
            <div id="people" className="w3-container resource w3-animate-zoom" style={{marginTop: 50}}>
              <h1 className="w3-xxxlarge w3-text-red"><b>People.</b></h1>
              <hr style={{width: 50, border: '5px solid red'}} className="w3-round" />
              <table id="searchTable">
                <tbody><tr className="header">
                    <th style={{width: '60%'}}>Name</th>
                    <th style={{width: '40%'}}>Heading 2</th>
                  </tr>
                  <tr>
                    <td>Kingsley Placeholder</td>
                    <td>Heading 2 Placeholder</td>
                  </tr>
                  <tr>
                    <td>Kingsley Placeholder</td>
                    <td>Heading 2 Placeholder</td>
                  </tr>
                  <tr>
                    <td>Kingsley Placeholder</td>
                    <td>Heading 2 Placeholder</td>
                  </tr>
                </tbody></table>
            </div>
            {/* Films */}
            <div id="films" className="w3-container resource w3-animate-zoom" style={{marginTop: 50, display: 'none'}}>
              <h1 className="w3-xxxlarge w3-text-red"><b>Films.</b></h1>
              <hr style={{width: 50, border: '5px solid red'}} className="w3-round" />
            </div>
            {/* Starships */}
            <div id="starships" className="w3-container resource w3-animate-zoom" style={{marginTop: 50, display: 'none'}}>
              <h1 className="w3-xxxlarge w3-text-red"><b>Starships.</b></h1>
              <hr style={{width: 50, border: '5px solid red'}} className="w3-round" />
            </div>
            {/* Vehicles */}
            <div id="vehicles" className="w3-container resource w3-animate-zoom" style={{marginTop: 50, display: 'none'}}>
              <h1 className="w3-xxxlarge w3-text-red"><b>Vehicles.</b></h1>
              <hr style={{width: 50, border: '5px solid red'}} className="w3-round" />
            </div>
            {/* Species */}
            <div id="species" className="w3-container resource w3-animate-zoom" style={{marginTop: 50, display: 'none'}}>
              <h1 className="w3-xxxlarge w3-text-red"><b>Species.</b></h1>
              <hr style={{width: 50, border: '5px solid red'}} className="w3-round" />
            </div>
            {/* Planets */}
            <div id="planets" className="w3-container resource w3-animate-zoom" style={{marginTop: 50, display: 'none'}}>
              <h1 className="w3-xxxlarge w3-text-red"><b>Planets.</b></h1>
              <hr style={{width: 50, border: '5px solid red'}} className="w3-round" />
            </div>
            {/* End page content */}
          </div>
          {/* Footer */}
          <div className="w3-light-grey w3-container w3-padding-32 w3-bottom" style={{marginTop: 50, paddingRight: 58}}>
            <p className="w3-right">©2017
              <br />Kingsley Chimezie - C14468272 
              <br />Dublin Institute of Technology - DT211C/4 </p>
          </div>
        </div>

        
        {/* end App */}
      </div>
    );
  }
}

export default App;
