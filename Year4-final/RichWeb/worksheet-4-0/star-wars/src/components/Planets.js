import React, { Component } from 'react';
import PlanetItem from './PlanetItem';
import PropTypes from 'prop-types';

class Planets extends Component {
  deletePlanet(id){
    this.props.onDelete(id);
  }

  render() {
    let planetItems;
    if (this.props.planets){
      planetItems = this.props.planets.map(planet => {
        // console.log(planet);
        return (
          <PlanetItem onDelete={this.deletePlanet.bind(this)} key={planet.name} planet={planet} />
        );
      });
    }
    return (
      <div className="Planets">
      <h3>Latest Planets</h3>
      {planetItems}
      </div>
    );
  }
}

Planets.propTypes = {
planets: PropTypes.array,
onDelete: PropTypes.func
}

export default Planets;
