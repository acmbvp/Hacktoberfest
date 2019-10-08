import React ,{Component} from 'react';
import MusicCard from '../MusicCard/MusicCard';
import './Tracks.css'

class Track extends Component{
    state={
        playing: false,
        preview_url: null,
        audio: null,
        paused: false
    }
    playAudio=(previewURL) => () => {
        if(!this.state.playing){
            if(this.state.paused){
                this.state.audio.play();
                this.setState({playing: true,paused:false})
            }else{
            const audio=new Audio(previewURL);
            audio.play();
            this.setState({playing: true,preview_url:previewURL,audio:audio,paused:false})
            }
        }
        else{
            if(previewURL===this.state.preview_url){
                this.state.audio.pause()
                this.setState({paused:true,playing:false})
            }
            else{
                this.state.audio.pause()
                const audio=new Audio(previewURL);
            audio.play();
            this.setState({playing: true,preview_url:previewURL,audio:audio,paused:false})
            }
        }
        
        
    }
    render(){
        const {tracks}=this.props;
        return(
            <div className="Tracks">
                {tracks.map(track => {
                    const {id , name ,album,preview_url} = track;
                    return(
                        <MusicCard key={id}
                            img_url={album.images[0].url}
                            clicked={this.playAudio(preview_url)}
                            url={preview_url}
                            name={name}
                            previewURL={this.state.preview_url}
                            playing={this.state.playing}>
                        </MusicCard>
                    )
                })}
            </div>
        )
    }
}

export default Track;