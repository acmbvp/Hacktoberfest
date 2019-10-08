import React from 'react';
import './MusicCard.css';
import 'font-awesome/css/font-awesome.min.css';

const MusicCard=(props)=>{
    var icon=<div className="fa fa-play-circle playPause" onClick={props.clicked}></div>;
    if(props.playing && props.previewURL===props.url){
        icon=<div className="fa fa-pause-circle playPause" onClick={props.clicked}></div>
    }
    return(
        <div className="MusicCard">
            <img src={props.img_url}
            className='AlbumImage' 
            alt={props.name}
            onClick={props.clicked}/>
            <span className="AlbumName">{props.name}</span>
            {icon }
        </div>
    )
}

export default MusicCard;