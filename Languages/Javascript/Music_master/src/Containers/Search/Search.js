import React , {Component} from 'react';
import './Search.css';

class Search extends Component {
    state={
        artistQuery: '',
        
    }

    clickChangeHandler=(event) => {
        this.setState({artistQuery:event.target.value})
    }
    keypressHandler=(event)=>{
        if(event.key==='Enter'){
            this.props.onSearchHandler(this.state.artistQuery)
        }
    }
    onSearchHandler=() => {
        this.props.onSearchHandler(this.state.artistQuery)
    }
    render(){
        return(
            <div>
                <input  className="SearchBar" 
                onChange={this.clickChangeHandler} 
                placeholder="Search Artist"
                onKeyPress={this.keypressHandler}/>
            <button onClick={this.onSearchHandler} 
            
            className="SearchButton"
            >SEARCH</button>
            </div>
            
        )
    }
}

export default Search