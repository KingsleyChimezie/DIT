import React, { Component } from 'react';
import uuid from 'uuid';
import PropTypes from 'prop-types';

class AddPlanet extends Component {
    constructor(){
        super();
        this.state = {
            newPlanet:{}
        }
    }

    static defaultProps = {
        rotation_periods: ['1', '25', '26']
    }

    handleSubmit(e){
        if(this.refs.name.value === ''){
            alert('Name is required!');
        } else {
            this.setState({newPlanet:{
                id: uuid.v4(),
                name: this.refs.name.value,
                rotation_period: this.refs.rotation_period.value
            }}, function(){
                // console.log(this.state);
                this.props.addPlanet(this.state.newPlanet);
            });
        }
        e.preventDefault();
    }

  render() {
    let rotation_periodOptions = this.props.rotation_periods.map(rotation_period => {
        return <option key={rotation_period} value={rotation_period}>{rotation_period}</option>
    })
    return (
      <div>
      <h3>Add Planet</h3>
      <form onSubmit={this.handleSubmit.bind(this)}>
          <div>
              <label>Name</label><br />
              <input type="text" ref="name" />
          </div>
          <div>
              <label>rotation_period</label><br />
              <select ref="rotation_period">
                {rotation_periodOptions}
              </select>
          </div>
          <br />
          <input type="submit" value="Submit" />
          <br />
      </form>
      </div>
    );
  }
}

AddPlanet.propTypes = {
    rotation_periods: PropTypes.array,
    addPlanet: PropTypes.func
}

export default AddPlanet;
