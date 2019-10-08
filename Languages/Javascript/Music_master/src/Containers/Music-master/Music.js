import React , {Component} from 'react';
import Artist from '../Artist/Artist';
import Search from '../Search/Search';
import Spinner from '../Spinner/Spinner'

const Api_URL='https://spotify-api-wrapper.appspot.com';

class Music extends Component {
    state={
        artist: null,
        tracks:[],
        loading :false
    }

    

    onSearchHandler=(artistQuery)=>{
        this.setState({loading:true})
        fetch(`${Api_URL}/artist/${artistQuery}`)
        .then(res=>res.json())
        .then(json => {
        if(json.artists.total>0){
            const artist=json.artists.items[0];
            this.setState({artist:artist});
            fetch(`${Api_URL}/artist/${artist.id}/top-tracks`)
            .then(res=>res.json())
            .then(json=>{this.setState({tracks:json.tracks,loading:false})})
            .catch(error=>alert(error.message))
        }
    })
    .catch(error=>alert(error.message));
    }
    render(){
        var artist=null;
        var spinner=null;
        if(this.state.loading){
            spinner=<Spinner />
        }
        if(this.state.artist!==null){
            artist=<Artist artist={this.state.artist} tracks={this.state.tracks}/>
        }
        return(
            <div>
            <Search onSearchHandler={this.onSearchHandler} />
            {artist}
            {spinner}
            </div>
        )
    }
}

export default Music;