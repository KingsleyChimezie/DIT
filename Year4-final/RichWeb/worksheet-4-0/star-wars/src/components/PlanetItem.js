import React, { Component } from 'react';
import PropTypes from 'prop-types';

class PlanetItem extends Component {
  deletePlanet(id){
    this.props.onDelete(id);
  }

  render() {
    return (
      <li className="Planet">
        <strong>{this.props.planet.name}</strong>: {this.props.planet.rotation_period} <button href="#" onClick={this.deletePlanet.bind(this, this.props.planet.id)}>X</button>
      </li>
    );
  }
}

PlanetItem.propTypes = {
  planet: PropTypes.object,
  onDelete: PropTypes.func
}

export default PlanetItem;
