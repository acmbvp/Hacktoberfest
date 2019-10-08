import React from 'react';
import './Spinner.css'

const Spinner = ()=>{
    return <div className="Spinner"><div className="loader">
    <div className="face">
      <div className="circle"></div>
    </div>
    <div className="face">
      <div className="circle"></div>
    </div>
  </div>
  </div>
}

export default Spinner