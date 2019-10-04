const fetch = require('cross-fetch')

const args = process.argv.slice(2)

async function izDog (dog) {
  try {
    if (!dog) throw new Error('Provide dog breed as first argument')

    const res = await fetch('https://dog.ceo/api/breeds/list/all')
    const body = await res.json()
    
    if (body.status !== 'success') throw new Error('Bad doggies')

    const breeds = Object.entries(body.message).map(([breed, types]) => {
      if (types.length) {
        return types.map(type => `${type} ${breed}`)
      }
      return breed
    })

    const foundDog = [].concat(...breeds).includes(dog)
    
    if (!foundDog) throw new Error('Dog breed not found')

    console.log('Woof!')
  } catch (err) {
    console.log('Yelp!', err.message)
  }
}

izDog(args[0])
