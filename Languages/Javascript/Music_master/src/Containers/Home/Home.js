import React , { Component } from 'react';
import 'font-awesome/css/font-awesome.min.css';
import './Home.css';
import Music from '../Music-master/Music';


class Home extends Component {
    state={
        search: false
    }
    changeToHomeHandler = () => {
        this.setState({search:false})
    }
    onclickHandler=() => {
        this.setState({search:true})
    }
    render(){
        var home=null;
        if(!this.state.search){
            home=(<div className="HomeMiddle">
                <h1>Music For Everyone.</h1>
                <h4>Million Of Songs.</h4>
                <br/>
                <button onClick={this.onclickHandler} className="PlayButton">play</button>
            </div>)
        }else{
            home=(
                <div className="HomeMiddle">
                    <Music />
                </div>
            )
        }
        return(
            <div>
                <div className="HomeHeader" >
                    <span className="HomeLeft">
                    <span className="HomeSpan">Music-Player</span>
                    <span onClick={this.changeToHomeHandler}
                    className="fa fa-spotify HomeSpan"></span></span>

                   <span className="HomeRight">
                        <span className="LightHeader HomeSpan">LogIn</span>
                        <span className="LightHeader HomeSpan">SignUp</span>
                        <span className="HomeSpan">Premium</span>
                        <span className="HomeSpan">Help</span>
                        <span className="HomeSpan">Download</span>                                        
                   </span>
                </div>
                {home}
                <div className="HomeFooter">
                <span onClick={this.changeToHomeHandler}
                    className="fa fa-spotify Symbol"></span>
                    <div className="Footers">
                    <span className="Footer1">
                        <span className="FooterHeading FoooterSpan">Company</span>
                        <span className="FoooterSpan">About</span>
                        <span className="FoooterSpan">Jobs</span>
                        <span className="FoooterSpan">FortheRecord</span>
                    </span>
                    <span className="Footer2">
                        <span className="FooterHeading FoooterSpan">Company</span>
                        <span className="FoooterSpan">For Artists</span>
                        <span className="FoooterSpan">Developers</span>
                        <span className="FoooterSpan">Brands</span>
                        <span className="FoooterSpan">Investors</span>
                    </span>
                    <span className="Footer3">
                        <span className="FooterHeading FoooterSpan">Company</span>
                        <span className="FoooterSpan">Help</span>
                        <span className="FoooterSpan">WebPlayer</span>
                    </span>
                    <span className="SocialHandles">
                        <span className='fa fa-instagram FooterSocial'></span>
                        <span className='fa fa-twitter FooterSocial'></span>
                        <span className='fa fa-facebook FooterSocial'></span>
                    </span>
                    </div>
                </div>
            </div>
        )
    }
}

export default Home;