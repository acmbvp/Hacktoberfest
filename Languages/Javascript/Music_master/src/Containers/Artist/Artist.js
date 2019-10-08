import React, { Component } from 'react';
import './Artist.css';
import Tracks from '../Tracks/Tracks';

class Artist extends Component {
    state={

    }

    render(){
        var followers=this.props.artist.followers.total
        var follower=followers%1000;
        followers=Math.floor(followers/1000);
        while(followers>0){
            follower=followers%1000+','+follower;
            followers=Math.floor(followers/1000);
        }
        return(
            <div className="Artist">
                <div className="ArtisInformation">
                <span>{this.props.artist.name}</span><br />
                <span>Total Followers-{follower}</span><br />
                <span>Genres- {this.props.artist.genres.join(', ')}</span><br />
                </div>
                <img src={this.props.artist.images[0].url} 
                className="ArtistImage"
                alt="Artist"/>
                
                <Tracks tracks={this.props.tracks} />
            </div>
        )
    }
}

export default Artist;